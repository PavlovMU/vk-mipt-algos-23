import java.util.HashMap;
import java.util.Map;

public class StrDiff {
    public static void extraLetter(String a, String b) {
        Map<Character, Integer> hashMapB = new HashMap<>();

        for (int i = 0; i < b.length(); i++) {
            char charB = b.charAt(i);
            hashMapB.put(charB, hashMapB.getOrDefault(charB, 0) + 1);
        }

        for (int i = 0; i < a.length(); i++) {
            char charA = a.charAt(i);
            if (hashMapB.containsKey(charA)) {
                hashMapB.put(charA, hashMapB.get(charA) - 1);
            }
        }

        for (Map.Entry<Character, Integer> entry : hashMapB.entrySet()) {
            if (entry.getValue() == 1) {
                System.out.println(entry.getKey());
                return;
            }
        }
    }

    public static void main(String[] args) {
        String a = "oiu";
        String b = "uosi";

        extraLetter(a, b);
    }

}


