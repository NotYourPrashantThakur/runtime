import subprocess

# Compile the Java source file
subprocess.run(['javac', 'RuntimeClassDumper.java'])

# Run the compiled Java class
subprocess.run(['java', 'RuntimeClassDumper'])
