import java.io.File;
import java.io.IOException;

public class invokeBat {
    public static void main(String[] args) throws IOException {
        File dir = new File("D:/");
        String target = "gal";
        System.out.println(findFile(dir, target));

    }

    public static String findFile(File dir, String fileName) {
        if (dir == null || !dir.exists() || dir.isFile()) {
            return "not found";
        }
        if (dir.getName().equals(fileName)) {
            return dir.getAbsolutePath();
        }

        File[] files = dir.listFiles();
        if (files != null) {
            for (var i : files) { // traverse all the sub directory
                if (i.isDirectory()) {

                    String result = findFile(i, fileName);
                    if (!result.equals("not found"))
                    return result;

                }

            }
        }

        return "not found";
    }

}
