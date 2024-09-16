package com.example.sumoftwo;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    Button b1;
    EditText i1,i2;
    TextView t1,result;

    String si1,si2;
    int a1,a2;


    @Override
    protected void onCreate(Bundle savedInstanceState) {


        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        b1=(Button) findViewById(R.id.button);
        i1=(EditText) findViewById(R.id.value1);
        i2=(EditText) findViewById(R.id.value2);
        t1=(TextView) findViewById(R.id.textView);
        result=(TextView) findViewById(R.id.result);





        b1.setOnClickListener(new View.OnClickListener() {

                                  @Override
                                  public void onClick(View view) {
                                      si1= i1.getText().toString();
                                      si2=i2.getText().toString();

                                      a1=Integer.parseInt(si1);
                                      a2=Integer.parseInt(si2);
                                      result.setText(Integer.toString(a1 + a2));
                                      Toast.makeText(MainActivity.this, "result :"+result.getText().toString(), Toast.LENGTH_SHORT).show();
                                  }
                              });


    }
}