import os
import shutil
import urllib.request
import urllib.error
import json
import time

SOLUTIONS_DIR = "solutions"
DIFFICULTY_DIRS = {"easy", "medium", "hard"}

def get_difficulty_from_leetcode(slug):
    url = "https://leetcode.com/graphql"
    query = """
    query getQuestion($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        difficulty
      }
    }
    """
    payload = json.dumps({"query": query, "variables": {"titleSlug": slug}}).encode()
    req = urllib.request.Request(
        url,
        data=payload,
        headers={
            "Content-Type": "application/json",
            "User-Agent": "Mozilla/5.0",
            "Referer": "https://leetcode.com",
        },
        method="POST"
    )
    try:
        with urllib.request.urlopen(req, timeout=10) as resp:
            data = json.loads(resp.read().decode())
            difficulty = data["data"]["question"]["difficulty"]
            return difficulty.lower()
    except Exception as e:
        print(f"  API error for {slug}: {e}")
        return None

def slug_from_folder(folder_name):
    # "0001-two-sum" → "two-sum"
    parts = folder_name.split("-", 1)
    return parts[1] if len(parts) > 1 else folder_name

def reorganize():
    if not os.path.exists(SOLUTIONS_DIR):
        print("solutions/ directory not found — nothing to reorganize.")
        return

    for item in os.listdir(SOLUTIONS_DIR):
        item_path = os.path.join(SOLUTIONS_DIR, item)

        if item in DIFFICULTY_DIRS or not os.path.isdir(item_path):
            continue

        slug = slug_from_folder(item)
        print(f"Fetching difficulty for: {slug}")
        difficulty = get_difficulty_from_leetcode(slug)
        time.sleep(0.5)   # be polite to the API

        if difficulty:
            target_dir = os.path.join(SOLUTIONS_DIR, difficulty)
            os.makedirs(target_dir, exist_ok=True)
            target_path = os.path.join(target_dir, item)
            if not os.path.exists(target_path):
                shutil.move(item_path, target_path)
                print(f"  ✓ Moved: {item} → {difficulty}/")
            else:
                print(f"  Already exists, skipping: {item}")
        else:
            print(f"  ⚠ Could not determine difficulty for: {item}")

if __name__ == "__main__":
    reorganize()
