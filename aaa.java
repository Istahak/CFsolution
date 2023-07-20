import java.util.*;

public class aaa {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = 1;
        while (scanner.hasNextLine()) {
            String str = scanner.nextLine();
            System.out.printf("Case %d: %s\n", t, can_rearrange_to_selise(str));
            t++;
        }
        scanner.close();
    }

    public static String can_rearrange_to_selise(String str) {
        Map<Character, Integer> freq = new HashMap<>();
        for (char c : str.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }

        Map<Character, Integer> selise = new HashMap<>();
        selise.put('S', 2);
        selise.put('E', 2);
        selise.put('L', 1);
        selise.put('I', 1);
        selise.put('D', 2);
        selise.put('G', 1);
        selise.put('T', 1);
        selise.put('A', 1);
        selise.put('P', 1);
        selise.put('O', 1);
        selise.put('R', 1);
        selise.put('M', 1);
        selise.put('F', 1);

        boolean has_selise = true;
        boolean has_selise_dp = true;

        for (Map.Entry<Character, Integer> entry : selise.entrySet()) {
            char c = entry.getKey();
            int count = entry.getValue();
            if (freq.getOrDefault(c, 0) < count) {
                has_selise = false;
            }
            if (c != 'O' && c != 'M' && freq.getOrDefault(c, 0) < count) {
                has_selise_dp = false;
            }
        }

        if (has_selise && has_selise_dp) {
            return "BOTH";
        } else if (has_selise) {
            return "SELISE";
        } else if (has_selise_dp) {
            return "SELISE Digital Platforms";
        } else {
            return "NONE";
        }
    }
}
