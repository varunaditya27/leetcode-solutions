import os
import shutil
import re

SOLUTIONS_DIR = "solutions"
DIFFICULTY_DIRS = {"easy", "medium", "hard"}

def get_difficulty(readme_path):
    try:
        with open(readme_path, "r", encoding="utf-8") as f:
            content = f.read().lower()
        for level in ["easy", "medium", "hard"]:
            if f"**difficulty:** {level}" in content or f"difficulty: {level}" in content:
                return level
    except Exception:
        pass
    return None

def reorganize():
    for item in os.listdir(SOLUTIONS_DIR):
        item_path = os.path.join(SOLUTIONS_DIR, item)

        # skip the easy/medium/hard folders themselves
        if item in DIFFICULTY_DIRS or not os.path.isdir(item_path):
            continue

        readme_path = os.path.join(item_path, "README.md")
        difficulty = get_difficulty(readme_path)

        if difficulty:
            target_dir = os.path.join(SOLUTIONS_DIR, difficulty)
            os.makedirs(target_dir, exist_ok=True)
            target_path = os.path.join(target_dir, item)
            if not os.path.exists(target_path):
                shutil.move(item_path, target_path)
                print(f"Moved: {item} → {difficulty}/")
            else:
                print(f"Already exists, skipping: {item}")
        else:
            print(f"Could not determine difficulty for: {item}")

if __name__ == "__main__":
    reorganize()