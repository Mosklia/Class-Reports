package online.sparky14145.DirLister;

import java.io.File;
import java.io.FilenameFilter;
import java.util.regex.Pattern;

public class FileFilter implements FilenameFilter {
    private final Pattern pattern;
    public FileFilter(String pattern) {
        this.pattern = Pattern.compile(".*" + pattern);
    }

    @Override
    public boolean accept(File dir, String name) {
//        System.out.println("--- " + name);
        return pattern.matcher(new File(name).getName()).matches();
    }
}
