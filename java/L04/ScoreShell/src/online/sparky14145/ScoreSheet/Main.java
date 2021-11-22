package online.sparky14145.ScoreSheet;

import java.io.File;
import java.io.IOException;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class Main {
    public static void main(String[] args) throws IOException {
        if (args.length == 0) {
            System.err.println("ERROR: Command not given!");
        } else if (args.length == 1) {
            System.err.println("ERROR: File not given!");
        } else if (args[0].equals("list")) {
            list(new File(args[1]));
        } else if (args[0].equals("add")) {
            if (args.length < 5) {
                System.err.println("ERROR: Syntax error!");
            } else {
                add(new File(args[1]), new ScoreSheetItem(args[2], args[3], Double.parseDouble(args[4])));
            }
        } else {
            System.err.println("ERROR: Unknown command!");
        }
    }

    public static void list(File file) throws IOException {
        ScoreSheet sheet = new ScoreSheet();

        sheet.readFrom(file);

        System.out.print(sheet);
    }

    public static void add(File file, ScoreSheetItem item) throws IOException {
        if (!file.exists()) {
            file.createNewFile();
        }

        ScoreSheet sheet = new ScoreSheet();

        sheet.readFrom(file);
        sheet.append(item);

        sheet.writeTo(file);
    }
}
