package conversion;
public class FahrToCels {
    double fahr;
    public FahrToCels(double fahr){
        this.fahr = fahr;
    }

    public double converted(){
        return (fahr - 32)* 5/9;
    }
}
