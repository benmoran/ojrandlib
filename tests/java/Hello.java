/* OneJoker RNG library <http://lcrocker.github.io/onejoker/ojrandlib>
 *
 * "Hello World" app included here to keep docs in sync with code.
 */
import com.onejoker.randlib.*;

public class Hello {
    static { System.loadLibrary("ojrand"); }

    private static final int[] gSeed = { 0x123, 0x234, 0x345, 0x456 };

    public static void main(String[] args) {
        Generator g = new Generator("mt19937");
        g.seed(gSeed);

        for (int i = 0; i < 100; ++i) {
            System.out.printf("%10u ", g.next32());
            if (4 == (i % 5)) System.out.printf("\n");
        }
    }
}