package online.sparky14145.DirLister;

import java.io.File;
import java.io.FilenameFilter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

/**
 * @brief List the files that match the pattern in a directory.
 */
public class DirLister implements DirListerInterface {

    public static void main(String[] args) {
        DirLister dirLister = new DirLister();

        if (Arrays.asList(args).contains("-h")) {
            printHelp();
        } else if (args.length == 0) {
            dirLister.interactiveMode();
        } else {
            dirLister.shellMode(args);
        }
    }

    public void interactiveMode() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("请输入待查询的路径：");
        File path = new File(scanner.nextLine());

        System.out.print("请输入待查询的后缀：");
        FileFilter filter = new FileFilter(scanner.nextLine());

        System.out.print("是否需要降序排序？[y/N]");
        FileComparator comp = new FileComparator(scanner.nextLine() == "y");

        this.listDir(path, filter, comp);
    }

    public void shellMode(String[] args) {
        if (args.length == 1) {
            args = new String[]{args[0], ""};
        }

        Comparator comp = new FileComparator(Arrays.asList(args).contains("-d"));
        File path = new File(args[0]);
        FileFilter filter = new FileFilter(args[1]);

        this.listDir(path, filter, comp);
    }

    @Override
    public void listDir(File path, FilenameFilter filter, Comparator comp) {
        if (!path.exists()) {
            System.err.println("路径错误: " + path.toString() + " 不存在！");
        } else if (!path.isDirectory()) {
            System.err.println("路径错误：" + path.toString() + " 不是一个目录！");
        } else {
            File[] files = path.listFiles(filter);
            Arrays.sort(files, comp);
            for (File file: files) {
                System.out.println(file);
            }
        }
    }

    public static void printHelp() {
        System.out.println("""
                使用方法: DirLister <目录名称> <模式> [选项] ...
                列出目录 <目录名称> 中所有后缀与 <模式> 相同的文件。
                
                可用选项:
                -d\t输出的文件名采用降序排序。
                -i\t输出的文件名采用升序排序。
                -h\t显示本帮助信息。
                """);
    }
}
