import os

# This is a hypothetical example and should not be executed on any system.
# Manipulating the file allocation table can cause data loss and system instability.

def infect_drive(drive_path):
    if not os.path.exists(drive_path):
        print(f"Drive path {drive_path} does not exist.")
        return

    print(f"Infecting drive at {drive_path}...")

    # This function will simulate corrupting the FAT
    fat_file = os.path.join(drive_path, 'FAT')
    
    try:
        with open(fat_file, 'r+b') as fat:
            fat_data = fat.read()
            # Simulate corruption by overwriting the FAT with garbage data
            fat.seek(0)
            fat.write(b'\x00' * len(fat_data))
            print("FAT has been corrupted.")
    except Exception as e:
        print(f"Failed to access or modify FAT: {e}")

def main():
    # Specify the drive path (this should be an actual path on a real system)
    drive_path = "/path/to/drive"

    # Confirm user wants to proceed
    confirm = input(f"Are you sure you want to corrupt the FAT on {drive_path}? (yes/no): ")
    if confirm.lower() == 'yes':
        infect_drive(drive_path)
    else:
        print("Operation cancelled.")

if __name__ == "__main__":
    main()
