import java.lang.reflect.Field;
import java.lang.reflect.Method;

public class RuntimeClassDumper {

    public static void dumpRuntimeClasses() {
        // Get the class loader of the current thread
        ClassLoader classLoader = Thread.currentThread().getContextClassLoader();

        // Iterate through all loaded classes
        for (Class<?> clazz : getLoadedClasses(classLoader)) {
            System.out.println("Class: " + clazz.getName());

            // Dump fields
            System.out.println("Fields:");
            for (Field field : clazz.getDeclaredFields()) {
                System.out.println(field.toString());
            }

            // Dump methods
            System.out.println("Methods:");
            for (Method method : clazz.getDeclaredMethods()) {
                System.out.println(method.toString());
            }

            System.out.println();
        }
    }

    private static Class<?>[] getLoadedClasses(ClassLoader classLoader) {
        try {
            // Get the 'classes' field from the ClassLoader class
            Field classesField = ClassLoader.class.getDeclaredField("classes");
            classesField.setAccessible(true);

            // Get the array of loaded classes
            Object classes = classesField.get(classLoader);

            // Convert the array to Class<?>[]
            if (classes instanceof Class<?>[]) {
                return (Class<?>[]) classes;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        return new Class<?>[0];
    }

    public static void main(String[] args) {
        dumpRuntimeClasses();
    }
}
