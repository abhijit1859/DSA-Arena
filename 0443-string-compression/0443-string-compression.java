class Solution {
    public int compress(char[] chars) {
        int index = 0; // Position to write compressed data
        int count = 1;

        for (int i = 1; i < chars.length; i++) {
            if (chars[i] == chars[i - 1]) {
                count++;
            } else {
                chars[index++] = chars[i - 1]; // Write the char

                if (count > 1) {
                    String ctr = String.valueOf(count);
                    for (int k = 0; k < ctr.length(); k++) {
                        chars[index++] = ctr.charAt(k);
                    }
                }

                count = 1; // Reset count for next group
            }
        }

        // Handle the last group
        chars[index++] = chars[chars.length - 1];
        if (count > 1) {
            String ctr = String.valueOf(count);
            for (int k = 0; k < ctr.length(); k++) {
                chars[index++] = ctr.charAt(k);
            }
        }

        return index;
    }
}
