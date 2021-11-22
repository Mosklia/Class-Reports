package online.sparky14145.DirLister;

import java.io.File;
import java.io.FilenameFilter;
import java.util.Comparator;

public interface DirListerInterface {
    public void listDir(File path, FilenameFilter filter, Comparator comp);
}
