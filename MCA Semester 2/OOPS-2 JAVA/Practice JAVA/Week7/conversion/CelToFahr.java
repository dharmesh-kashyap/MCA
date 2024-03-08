package conversion;
public class CelToFahr {
    double cels;
   public CelToFahr(double cels){
        this.cels = cels;
    }

    public double converted(){
        return (cels*9/5)+32;
    }
}
