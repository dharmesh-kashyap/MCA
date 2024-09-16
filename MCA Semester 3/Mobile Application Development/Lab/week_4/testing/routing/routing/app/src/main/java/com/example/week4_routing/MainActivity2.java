package com.example.week4_routing;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity2 extends AppCompatActivity {
    TextView t1;
    Button b1;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        b1=(Button)findViewById(R.id.buttonback);
        t1 = findViewById(R.id.textViews);

        Intent third = getIntent();
        String msg = third.getStringExtra("Text");
        t1.setText("Second Page... " + msg);

        Toast.makeText(MainActivity2.this, "Second Page opening", Toast.LENGTH_SHORT).show();
        b1.setOnClickListener(v->{
            finish();
        });


    }

}
