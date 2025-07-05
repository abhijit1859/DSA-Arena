class Solution {
    public int calPoints(String[] operations) {
        List<Integer> list = new ArrayList<>();
        for (String op : operations) {
            if (op.equals("+")) {
                int a = list.get(list.size() - 1);
                int b = list.get(list.size() - 2);
                list.add(a + b);
            } else if (op.equals("C")) {
                list.remove(list.size() - 1);
            } else if (op.equals("D")) {
                int n = list.get(list.size() - 1) * 2;
                list.add(n);
            } else {
                list.add(Integer.parseInt(op));
            }
        }

        int sum = 0;
        for (int score : list) {
            sum += score;
        }
        return sum;
    }
}
