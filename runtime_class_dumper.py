import os
import subprocess

def get_apk_path(package_name):
    # Find the APK file path based on the package name
    result = subprocess.run(['pm', 'path', package_name], capture_output=True, text=True)
    apk_path = result.stdout.strip().replace('package:', '')
    return apk_path

def dump_runtime_classes(package_name):
    apk_path = get_apk_path(package_name)
    if apk_path:
        # Convert APK to JAR using dex2jar
        jar_path = os.path.join(os.getcwd(), 'output.jar')
        subprocess.run(['sh', '-c', f'd2j-dex2jar {apk_path} -o {jar_path}'])

        # Extract classes from JAR using jd-cli
        classes_dir = os.path.join(os.getcwd(), 'classes')
        subprocess.run(['sh', '-c', f'jd-cli -od {classes_dir} {jar_path}'])

        # Print the content of the extracted classes
        for root, dirs, files in os.walk(classes_dir):
            for file in files:
                if file.endswith('.java'):
                    with open(os.path.join(root, file), 'r') as f:
                        print(f.read())

        # Clean up temporary files
        os.remove(jar_path)
        subprocess.run(['rm', '-rf', classes_dir])
    else:
        print("APK file not found for the specified package name.")

# Specify the package name of your app
package_name = 'com.pubg.krmobile'

# Call the function to dump the runtime classes
dump_runtime_classes(package_name)
