class Solution {
    public int maxVowels(String s, int k) {

        int count = 0;
        int maxi = 0;

        // Step 1: Count vowels in the first window
        for (int i = 0; i < k; i++) {
            if (isVowel(s.charAt(i))) {
                count++;
            }
        }

        maxi = count;

        // Step 2: Slide the window
        for (int i = k; i < s.length(); i++) {

            // Remove outgoing character
            if (isVowel(s.charAt(i - k))) {
                count--;
            }

            // Add incoming character
            if (isVowel(s.charAt(i))) {
                count++;
            }

            maxi = Math.max(maxi, count);

            if (maxi == k) {
                return maxi;
            }
        }

        return maxi;
    }

    // Step 3: Check whether character is a vowel
    private boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }
}
