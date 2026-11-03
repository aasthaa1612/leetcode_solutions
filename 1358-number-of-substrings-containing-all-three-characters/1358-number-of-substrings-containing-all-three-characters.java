class Solution {
    public int numberOfSubstrings(String s) {

        int left = 0;
        int count = 0;
        int n = s.length();

        int[] freq = new int[3];

        for (int right = 0; right < n; right++) {

            // Add the current character
            freq[s.charAt(right) - 'a']++;

            // Check if window contains a, b and c
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {

                // Count all valid substrings
                count += n - right;

                // Remove the leftmost character
                freq[s.charAt(left) - 'a']--;

                // Move left forward
                left++;
            }
        }

        return count;
    }
}
