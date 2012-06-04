import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(terminalReader());
		while (scanner.hasNext()) {
			String line = scanner.nextLine();
			String[] numbers = line.split("\\s+");
			BigDecimal r = new BigDecimal(numbers[0].trim());
			BigDecimal result = r.pow(Integer.valueOf(numbers[1].trim()));
			String resultString = result.stripTrailingZeros().toPlainString().replaceFirst("^0+", "");
			System.out.println(resultString);
		}
		scanner.close();
	}

	private static BufferedReader fileReader() throws FileNotFoundException {
		return new BufferedReader(new FileReader(new File("in.txt")));
	}

	private static BufferedReader terminalReader() {
		return new BufferedReader(new InputStreamReader(System.in));
	}
}