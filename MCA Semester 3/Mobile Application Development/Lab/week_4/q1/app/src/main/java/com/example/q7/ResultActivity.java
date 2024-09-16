package com.example.q7;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.Button;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class ResultActivity extends AppCompatActivity {
    TextView gender;
    TextView likes;
    ImageView boyimg;
    ImageView girlimg;
    Button back;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_result);
        gender = (TextView) findViewById(R.id.gender);
        likes = ( TextView) findViewById(R.id.likes);
        boyimg = (ImageView) findViewById(R.id.boy);
        girlimg = (ImageView) findViewById(R.id.girl);
        back = (Button) findViewById(R.id.back);
        Intent resPage = getIntent();
        String[] msg=resPage.getStringArrayExtra("Text");
        if(msg!=null) {
            gender.setText(msg[0]+" is "+msg[2]);
            if(msg[2].equals("male")){
                boyimg.setVisibility(View.VISIBLE);
            }else {
                girlimg.setVisibility(View.VISIBLE);
            }
            if(msg[1].isEmpty()){
                likes.setText(msg[0]+" Likes Nothing!");
            }else{
                likes.setText(msg[0]+" likes "+msg[1]+" !");
            }
        }else{
            Toast.makeText(ResultActivity.this,"Error while recieving data from form!!",Toast.LENGTH_SHORT).show();
        }
    }

    public void onBackClick(View view) {
        Intent goBack = new Intent( ResultActivity.this,MainActivity.class);
        startActivity(goBack);
        finish();
    }
}