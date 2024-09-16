package com.example.myapplication;

import static com.example.myapplication.R.id.custom_toast;

import android.annotation.SuppressLint;
import android.content.Context;
import android.media.Image;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener {
    LayoutInflater li;
    View layout;
    Toast T;
    String[] banks = {"Select", "Axis", "StateBankOfIndia", "Canara", "HDFC", "UnionBank"};
    ArrayAdapter aa;
    Spinner sp;
    TextView tt;
    ImageView iv;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        sp = (Spinner) findViewById(R.id.spinner);
        aa = new ArrayAdapter(this, android.R.layout.simple_spinner_item, banks);
        aa.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        sp.setAdapter(aa);
        sp.setOnItemSelectedListener(this);
        tt = (TextView) findViewById(R.id.textView);
        iv = (ImageView) findViewById(R.id.imageView);
    }

    @Override
    public void onItemSelected(AdapterView<?> arg0, View arg1, int pos, long id) {
        setIVBackground(pos);
    }

    @Override
    public void onNothingSelected(AdapterView<?> adapterView) {

    }
    public void setIVBackground(int p) {
        String bankName = banks[p];
        if (bankName.isEmpty()) return;

        String imageName = bankName.toLowerCase().trim();
        int resourceId = getResources().getIdentifier(imageName, "drawable", getPackageName());
        if (resourceId != 0) {
            li = getLayoutInflater();
            layout = li.inflate(R.layout.custom_toast, (ViewGroup) findViewById(R.id.custom_toast));
            iv = layout.findViewById(R.id.imageView);
            tt = layout.findViewById(R.id.textView);
            iv.setImageResource(resourceId);
            tt.setText("You have selected "+banks[p]+".");
            Toast toast = new Toast(getApplicationContext());
            toast.setDuration(Toast.LENGTH_SHORT);
            toast.setView(layout);
            toast.show();
        }
    }
}