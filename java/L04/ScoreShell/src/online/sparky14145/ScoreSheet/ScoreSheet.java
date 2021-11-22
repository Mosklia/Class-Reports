package online.sparky14145.ScoreSheet;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ScoreSheet {
    private List<ScoreSheetItem> elems;

    public ScoreSheet() {
        elems = new ArrayList<ScoreSheetItem>();
    }

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();

        for (ScoreSheetItem item : elems) {
            res.append(item.toString()).append('\n');
        }

        return res.toString();
    }

    public void append(ScoreSheetItem item) {
        elems.add(item);
    }

    public void readFrom(File file) throws IOException {
        try (FileInputStream input = new FileInputStream(file)) {
            Scanner scanner = new Scanner(input);
            elems.clear();

            while (scanner.hasNextLine()) {
                String temp = scanner.nextLine();

                if (!temp.isEmpty()) {
                    elems.add(ScoreSheetItem.fromString(temp));
                }
            }
        }
    }

    public void writeTo(File file) throws IOException {
        try (FileOutputStream output = new FileOutputStream(file)) {
            output.write(this.toString().getBytes(StandardCharsets.UTF_8));
        }
    }
}
