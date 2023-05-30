import java.lang.instrument.Instrumentation;
import java.lang.reflect.Field;
import java.lang.reflect.Method;

public class RuntimeClassDumper {

    public static void dumpRuntimeClasses() throws ClassNotFoundException, NoSuchMethodException, IllegalAccessException {
        Class<?>[] loadedClasses = getAllLoadedClasses();
        if (loadedClasses != null) {
            for (Class<?> clazz : loadedClasses) {
                System.out.println("Class: " + clazz.getName());

                System.out.println("Fields:");
                for (Field field : clazz.getDeclaredFields()) {
                    System.out.println(field.toString());
                }

                System.out.println("Methods:");
                for (Method method : clazz.getDeclaredMethods()) {
                    System.out.println(method.toString());
                }

                System.out.println();
            }
        } else {
            System.out.println("Failed to get loaded classes.");
        }
    }

    private static Class<?>[] getAllLoadedClasses() throws ClassNotFoundException, NoSuchMethodException, IllegalAccessException {
        Instrumentation instrumentation = java.lang.instrument.Instrumentation.class.cast(
                ClassLoader.getSystemClassLoader().loadClass("java.lang.instrument.Instrumentation")
                        .getMethod("getInstrumentation")
                        .invoke(null)
        );

        return instrumentation.getAllLoadedClasses();
    }

    public static void main(String[] args) throws ClassNotFoundException, NoSuchMethodException, IllegalAccessException {
        dumpRuntimeClasses();
    }
}
