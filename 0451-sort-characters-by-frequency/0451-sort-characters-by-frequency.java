class Solution {
    public String frequencySort(String s) {
        HashMap<Character, Integer> freq = new HashMap<>();
        for(int i=0;i<s.length();i++){
            char key = s.charAt(i);
            if (freq.containsKey(key)) { 
                freq.put(key, freq.get(key) + 1);
            } else {
                freq.put(key, 1);
            }

        }
        
        ArrayList<Map.Entry<Character, Integer>> list = new ArrayList<>(freq.entrySet());

        // Step 3: Sort by frequency in descending order
        Collections.sort(list, new Comparator<Map.Entry<Character, Integer>>() {
            public int compare(Map.Entry<Character, Integer> a, Map.Entry<Character, Integer> b) {
                return b.getValue() - a.getValue(); // Descending
            }
        });

        // Step 4: Build the output string
        StringBuilder result = new StringBuilder();
        for (Map.Entry<Character, Integer> entry : list) {
            char ch = entry.getKey();
            int count = entry.getValue();
            for (int i = 0; i < count; i++) {
                result.append(ch);
            }
        }

        return result.toString();
    }
}
