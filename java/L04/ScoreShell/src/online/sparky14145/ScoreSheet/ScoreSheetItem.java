package online.sparky14145.ScoreSheet;

public class ScoreSheetItem {
    private String name;
    private String id;
    private double score;

    public ScoreSheetItem(String name, String id, double score) {
        this.setName(name);
        this.setId(id);
        this.setScore(score);
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setScore(double score) {
        this.score = score;
    }

    public String getName() {
        return name;
    }

    public double getScore() {
        return score;
    }

    public String getId() {
        return id;
    }

    public static ScoreSheetItem fromString(String source) throws IllegalArgumentException {
        String[] splitSource = source.split(" ");

        if (splitSource.length != 3) {
            throw new IllegalArgumentException("记录需要 3 项数据，但得到了 " + splitSource.length + "项");
        }

        return new ScoreSheetItem(splitSource[0], splitSource[1], Double.parseDouble(splitSource[2]));
    }

    @Override
    public String toString() {
        return name + ' ' + id + ' ' + score;
    }
}
