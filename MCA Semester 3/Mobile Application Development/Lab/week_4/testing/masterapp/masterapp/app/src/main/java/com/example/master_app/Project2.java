package com.example.master_app;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class Project2 extends AppCompatActivity{
    Button btn1,btn2,btn3,btn4,btn5,btn6,btn7,btn8,btn9,btn0,btnplus,btnsub,btnclear,btndot,btnmul,btndiv,btneql;
    TextView t1;
    float num1,num2,result;
    boolean add,sub,mul,div;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_project2);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
        btn1=(Button) findViewById(R.id.button1);
        btn2=(Button) findViewById(R.id.button2);
        btn3=(Button) findViewById(R.id.button3);
        btn4=(Button) findViewById(R.id.button4);
        btn5=(Button) findViewById(R.id.button5);
        btn6=(Button) findViewById(R.id.button6);
        btn7=(Button) findViewById(R.id.button7);
        btn8=(Button) findViewById(R.id.button8);
        btn9=(Button) findViewById(R.id.button9);
        btn0=(Button) findViewById(R.id.button0);
        btnplus=(Button) findViewById(R.id.buttonplus);
        btnsub=(Button) findViewById(R.id.buttonsub);
        btnmul=(Button) findViewById(R.id.buttonmul);
        btndiv=(Button) findViewById(R.id.buttondiv);
        btnclear=(Button) findViewById(R.id.buttonC);
        btndot=(Button) findViewById(R.id.buttondot);
        btneql=(Button) findViewById(R.id.buttonequal);
        t1=(TextView)findViewById(R.id.textView1);
        btnclear.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                t1.setText("");

            }
        });
        btn0.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                t1.setText(t1.getText()+"0");
            }
        });

        btn1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                t1.setText(t1.getText()+"1");

            }
        });
        btn2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                t1.setText(t1.getText()+"2");
            }
        });
        btn3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                t1.setText(t1.getText()+"3");
            }
        });
        btn4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                t1.setText(t1.getText()+"4");
            }
        });
        btn5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                t1.setText(t1.getText()+"5");
            }
        });
        btn6.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                t1.setText(t1.getText()+"6");
            }
        });
        btn7.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                t1.setText(t1.getText()+"7");
            }
        });
        btn8.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                t1.setText(t1.getText()+"8");
            }
        });
        btn9.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                t1.setText(t1.getText()+"9");
            }
        });
        btndot.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                t1.setText(t1.getText()+".");
            }
        });
        btnplus.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (t1.getText()==null){
                    t1.setText("");

                }else{
                    num1=Float.parseFloat(t1.getText().toString());
                    t1.setText(null);
                    add=true;
                }
            }
        });
        btnsub.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (t1.getText()==null){
                    t1.setText("");

                }else{
                    num1=Float.parseFloat(t1.getText().toString());
                    sub=true;
                    t1.setText(null);
                }

            }
        });
        btnmul.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (t1.getText()==null){
                    t1.setText("");

                }else{
                    num1=Float.parseFloat(t1.getText().toString());
                    mul=true;
                    t1.setText(null);
                }
            }
        });
        btndiv.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (t1.getText()==null){
                    t1.setText("");

                }else{
                    num1=Float.parseFloat(t1.getText().toString());
                    div=true;
                    t1.setText(null);
                }
            }
        });
        btneql.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                num2=Float.parseFloat(t1.getText().toString());
                if(add==true){
                    t1.setText(String.valueOf(num1+num2));
                    add=false;
                }else if(sub==true){
                    t1.setText(String.valueOf(num1-num2));
                    sub=false;
                }else if(mul==true){
                    t1.setText(String.valueOf(num1*num2));
                    mul=false;
                }else if(div==true){
                    t1.setText(String.valueOf(num1/num2));
                    div=false;
                }
            }
        });

    }
}