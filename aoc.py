import argparse
import os
import subprocess

AOC_DIR = os.getenv('AOC')

def get_args():
    parser = argparse.ArgumentParser(description="Configure, build, or clean this project")
    parser.add_argument("action", choices=["configure", "build", "clean"], help="Action to perform onto project (configure, build, or clean)")

    return parser.parse_args()

def configure_project():
    result = subprocess.run(["cmake", ".."], cwd=AOC_DIR + "build/", stdout=subprocess.PIPE, text=True)
    print(result.stdout)

def build_project():
    result = subprocess.run(["make"], cwd=AOC_DIR + "build/", stdout=subprocess.PIPE, text=True)
    print(result.stdout)

    # move executable to aoc/bin/
    subprocess.run(["mkdir", "-p", "bin/"], cwd=AOC_DIR)
    subprocess.run(["cp", AOC_DIR + "build/2024/2024", AOC_DIR + "bin/"])

if __name__ == "__main__":
    if get_args().action == "configure":
        configure_project()
    elif get_args().action == "build":
        build_project()
    else:
        print(get_args().action, "is not implemented yet")
