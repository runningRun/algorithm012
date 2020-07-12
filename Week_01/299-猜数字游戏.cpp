class Solution {
public:
    string getHint(string secret, string guess) {
        int containChars[10] = {0};
        int index = 0;
        int bulls = 0;
        int cows = 0;

        for (index = 0; index < secret.size(); ++index) 
            containChars[secret[index] - '0'] += 1;

        for (index = 0; index < guess.size(); ++index) {
            if (guess[index] == secret[index]) {
                bulls += 1;
                containChars[guess[index] - '0'] -= 1;
            } 
        }

        for (index = 0; index < guess.size(); ++index) {
            if (guess[index] != secret[index] && (containChars[guess[index] - '0'] > 0)) {
                cows += 1;
                containChars[guess[index] - '0'] -= 1;
            } 
        }

        int n = 1 + snprintf(NULL, 0, "%dA%dB", bulls, cows);
        char *tmpValue = (char *)malloc(n);
        snprintf(tmpValue, n, "%dA%dB", bulls, cows);

        string result(tmpValue);
        free(tmpValue);
        return result;
    }
};