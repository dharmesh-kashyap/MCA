package com.example.week4_routing;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ToggleButton;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    Button b1;
    TextView t1;
    ImageView i1;
    EditText e1;
    RadioGroup rg1;
    CheckBox c1, c2, c3;
    ToggleButton toggle;
    String previousName;
    boolean isChecked;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Initialize views
        b1 = findViewById(R.id.b1);
        toggle=findViewById(R.id.togglebtn);
        t1 = findViewById(R.id.result);  // Make sure the ID matches the one in your XML
        i1 = findViewById(R.id.image);    // Make sure the ID matches the one in your XML
        e1 = findViewById(R.id.name);
        rg1 = findViewById(R.id.grp);
        c1 = findViewById(R.id.sprots);  // Corrected ID for sports
        c2 = findViewById(R.id.sing); // Corrected ID for singing
        c3 = findViewById(R.id.dance);

        // Set initial visibility
        t1.setVisibility(View.INVISIBLE);
        i1.setVisibility(View.INVISIBLE);

        // Set up button click listener
        b1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                // Make TextView and ImageView visible when button is clicked
                t1.setVisibility(View.VISIBLE);
                i1.setVisibility(View.VISIBLE);

                // Get selected RadioButton ID
                int selectedId = rg1.getCheckedRadioButtonId();

                // Check if a RadioButton is selected
                if (selectedId == -1) {
                    t1.setText("Please select a gender.");
                } else {
                    // Find the selected RadioButton
                    RadioButton selectedRadioButton = findViewById(selectedId);
                    String genderPrefix = "";

                    // Determine gender prefix based on selected RadioButton
                    if (selectedRadioButton.getId() == R.id.male) {
                        genderPrefix = "Mr.";
                    } else if (selectedRadioButton.getId() == R.id.female) {
                        genderPrefix = "Mrs.";
                    }

                    StringBuilder hobbies = new StringBuilder();
                    if (c1.isChecked()) hobbies.append("sports ");
                    if (c2.isChecked()) hobbies.append("singing ");
                    if (c3.isChecked()) hobbies.append("dance ");
                    if (hobbies.length() == 0) hobbies.append("no hobbies selected");



                    // Set the text in TextView
                    String msg=genderPrefix + " " + e1.getText().toString();
                    msg+=" \nHobbies: "+hobbies.toString();

                    Intent intent =new Intent(MainActivity.this,
                            MainActivity2.class);
                    intent.putExtra("Text",msg);
                    startActivity(intent);





                }
            }
   });
        toggle.setOnCheckedChangeListener((buttonView,isChecked)->{
            if(isChecked){
                previousName=e1.getText().toString();
                e1.setText("");
            }
            else{
                if(!previousName.isEmpty())
                {
                    e1.setText(previousName);
                }
                else{
                    Toast.makeText(MainActivity.this, "No name to restore", Toast.LENGTH_SHORT).show();
                }
            }
        });
}
}