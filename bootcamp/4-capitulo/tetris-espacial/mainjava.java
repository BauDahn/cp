import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    
    public static void torres(int n, int origen, int destino, int auxiliar, PrintWriter out) {
        if (n == 0) return;  // Es el caso base

        torres(n - 1, origen, auxiliar, destino, out); // Movemos las n - 1 naves al hangar auxiliar

        out.println(origen + " " + destino);

        torres(n - 1, auxiliar, destino, origen, out); // Movemos las n - 1 naves del auxiliar al destino final
    }

    public static void main(String[] args) throws IOException {
        // Líneas de optimización para la programación competitiva
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = null;

        String line = br.readLine();
        if (line != null) {
            st = new StringTokenizer(line);
            int n = Integer.parseInt(st.nextToken());

            int k = (1 << n) - 1; // El total de movimientos es 2^n - 1
            out.println(k);

            // Ahora mostramos el recorrido con la función recursiva
            torres(n, 1, 3, 2, out);
        }
        
        // Es fundamental vaciar el buffer al final para asegurar que todo se imprima correctamente
        out.flush();
    }
}