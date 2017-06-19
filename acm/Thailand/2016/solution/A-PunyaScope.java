import java.io.*;
import java.util.*;

public class A_PunyaScope_OK {

	final static long MOD = 5L * (1 << 25) + 1; // use Z/(c*2^k + 1)Z
	final static int maxOrder = 16; // max degree is 2^16 = 65536
	static long princRoot = 243;
	static {
		for (int k = 25; k > maxOrder; --k)
			princRoot = (princRoot * princRoot) % MOD;
	}

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int numCases = in.nextInt();
		String[] pairs = { "at", "ta", "gc", "cg" };
		for (int k = 0; k < numCases; ++k) {
			String st = in.next();
			long[] total = new long[st.length()];
			for (int i = 0; i < pairs.length; ++i) {
				long[] count = mkHist(st, pairs[i].charAt(0), pairs[i].charAt(1));
				for (int j = 0; j < total.length; ++j) {
					total[j] += count[j];
				}
			}

			long maxFreq = Arrays.stream(total).max().getAsLong();

			for (int i = total.length - 1; i >= 1; --i)
				if (total[i] == maxFreq) {
					out.printf("%d\n", i);
					break;
				}
		}
		in.close();
		out.close();
	}

	static long[] fft(long[] x, long g) {
		int n = x.length;
		if (n == 1)
			return x;

		long[] x0 = new long[n / 2], x1 = new long[n / 2];
		for (int i = 0; i < n / 2; ++i) {
			x0[i] = x[2 * i];
			x1[i] = x[2 * i + 1];
		}
		x0 = fft(x0, (g * g) % MOD);
		x1 = fft(x1, (g * g) % MOD);

		long w = 1;
		long[] a = new long[n];
		for (int i = 0; i < n / 2; ++i, w = w * g % MOD) {
			a[i] = (x0[i] + w * x1[i] % MOD + MOD) % MOD;
			a[i + n / 2] = (x0[i] - w * x1[i] % MOD + MOD) % MOD;
		}
		return a;
	}

	public static long inv(long N, long M) {
		long x = 0, lastx = 1, y = 1, lasty = 0, q, t, a = N, b = M;
		while (b != 0) {
			q = a / b;
			t = a % b;
			a = b;
			b = t;
			t = x;
			x = lastx - q * x;
			lastx = t;
			t = y;
			y = lasty - q * y;
			lasty = t;
		}
		return (lastx + M) % M;
	}

	static long[] mult(long[] x, long[] y) {
		int n = x.length;
		x = fft(x, princRoot);
		y = fft(y, princRoot);
		// System.out.println("F(x): " + Arrays.toString(x));
		// System.out.println("F(y): " + Arrays.toString(y));
		long a[] = new long[n];
		long r = inv(n, MOD);
		for (int i = 0; i < x.length; ++i)
			a[i] = x[i] * y[i] % MOD * r % MOD;

		// System.out.println("Fourier product: " + Arrays.toString(a));
		return fft(a, inv(princRoot, MOD));
	}

	static long[] mkHist(String st, char a, char b) {
		int n = 1 << maxOrder, stn = st.length();
		int mid = n / 2;
		long[] x = new long[n];
		long[] y = new long[n];

		for (int i = 0; i < stn; ++i) {
			if (st.charAt(i) == b)
				x[i] = 1;
			else if (st.charAt(i) == a)
				y[mid - i] = 1;
		}
		long[] xy = mult(x, y);
		long[] hist = new long[stn];
		for (int i = 0; i < stn; ++i)
			hist[i] = xy[mid + i];
		return hist;
	}
}