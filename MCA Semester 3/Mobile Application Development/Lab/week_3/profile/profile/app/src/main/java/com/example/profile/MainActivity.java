package com.example.profile;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.text.Editable;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity{
    EditText name;
    RadioGroup group;

    CheckBox sport,dance,reading;
    Button click;
    ImageView img;
    TextView t1,t2,t3;
    String gender="";
    String str_name;

    @SuppressLint({"MissingInflatedId", "WrongViewCast"})
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
        name=(EditText) findViewById(R.id.editTextname);
        group=(RadioGroup) findViewById(R.id.rgroup);

        sport=(CheckBox) findViewById(R.id.sport);
        dance=(CheckBox) findViewById(R.id.dance);
        reading=(CheckBox) findViewById(R.id.reading);
        click=(Button) findViewById(R.id.clickme);
        img=(ImageView) findViewById(R.id.imageView2);
        t1=(TextView) findViewById(R.id.displayname);
        t2=(TextView) findViewById(R.id.displaygender);
        t3=(TextView) findViewById(R.id.displayhoby);

        group.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {

            @Override
            public void onCheckedChanged(RadioGroup radioGroup, int i) {
                int selectedId=group.getCheckedRadioButtonId();
                if(selectedId==R.id.maleradio) {
                    gender = "Male";
                }else if(selectedId==R.id.femaleradio) {
                    gender = "Female";
                }else{
                    gender="Others";
                }
            }
        });
        sport.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean b) {
                if(b){
                    Toast.makeText(MainActivity.this, "hobby is sports", Toast.LENGTH_SHORT).show();
                }
            }
        });
        dance.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean b) {
                if(b){
                    Toast.makeText(MainActivity.this, "hobby is dancing", Toast.LENGTH_SHORT).show();
                }
            }
        });
        reading.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean b) {
                if(b){
                    Toast.makeText(MainActivity.this, "hobby is reading", Toast.LENGTH_SHORT).show();
                }
            }
        });
        click.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                str_name=name.getText().toString();
                t1.setText("Hello "+str_name);
                String userhobies="";
                if(sport.isChecked()) {
                    userhobies += "Sports,";
                }
                if(dance.isChecked()) {
                    userhobies += " Dance,";
                }
                if(reading.isChecked()){
                    userhobies+=" Reading";
                }
                t2.setText(str_name+" is "+gender);
                t3.setText(str_name+" likes "+userhobies);
                img.setVisibility(view.VISIBLE);


            }
        });


    }
}