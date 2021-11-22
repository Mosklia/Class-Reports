package online.sparky14145.DirLister;

import java.io.File;
import java.io.IOException;
import java.lang.reflect.Array;
import java.nio.file.Files;
import java.nio.file.LinkOption;
import java.nio.file.attribute.BasicFileAttributeView;
import java.nio.file.attribute.FileTime;
import java.util.Arrays;
import java.util.Comparator;

public class FileComparator implements Comparator<File> {
    private final boolean descend; // 控制是否降序排列

    public FileComparator(boolean descend) {
        this.descend = descend;
    }

    @Override
    public int compare(File file, File t1) {
        int multiplier = descend ? -1 : 1;
        int result;

        try {
            FileTime time1 = Files.getLastModifiedTime(file.toPath());
            FileTime time2 = Files.getLastModifiedTime(t1.toPath());
            result = time1.compareTo(time2);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return multiplier;
    }
}
