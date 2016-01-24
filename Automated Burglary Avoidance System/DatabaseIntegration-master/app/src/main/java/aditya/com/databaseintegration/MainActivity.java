package aditya.com.databaseintegration;

import android.app.ProgressDialog;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.StrictMode;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Toast;

import org.apache.http.HttpEntity;
import org.apache.http.HttpHost;
import org.apache.http.HttpRequest;
import org.apache.http.HttpResponse;
import org.apache.http.NameValuePair;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.ResponseHandler;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.client.methods.HttpUriRequest;
import org.apache.http.conn.ClientConnectionManager;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.params.HttpParams;
import org.apache.http.protocol.HttpContext;
import org.json.JSONArray;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

import android.os.Handler;//auto refresh


/**
 * Code to demonstrate the insertion of data into android application.
 * Also demonstrates how to retrieve the data.
 * Uses the localhost for local server.
 * Php scripting language for backend integration.
 */

public class MainActivity extends ActionBarActivity {

    //EditText etName, etEmail, etPhone;
    Button bSubmit;
    ListView listView;
    public static String url1 = "http://www.wifimodule.esy.es/tutorial.php";
    public static String url2 = "http://www.wifimodule.esy.es/tut.php";
    //String name, email, phone;
    String result = "", line = "";
    String value;
    int values;
    String[] combinedArray;
    String combinedText = "";
    ProgressDialog progressDialog;

    //Handler mHandler;//auto refresh

    InputStream is = null;
    String exceptionMessage = "There seems to be some problem connecting to database. " +
            "Please check your Internet Connection and try again.";
    String successMessage = "Data has been entered successfully and request for blocking the door is made";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        listView = (ListView) findViewById(R.id.listView);
        new RetrieveTask().execute();

        StrictMode.ThreadPolicy threadPolicy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
        StrictMode.setThreadPolicy(threadPolicy);

        //etName = (EditText) findViewById(R.id.etName);
        //etEmail = (EditText) findViewById(R.id.etEmail);
        //etPhone = (EditText) findViewById(R.id.etPhone);
        bSubmit = (Button) findViewById(R.id.button_submit);

        bSubmit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                //name = etName.getText().toString();
                //email = etEmail.getText().toString();
                //phone = etPhone.getText().toString();
                value = "1";

                /*if(name.equals("") ||
                        email.equals("") ||
                        phone.equals("")){
                    String msg = "One or more fields are empty";
                    etName.setText("");
                    etEmail.setText("");
                    etPhone.setText("");
                }
                else{*/

                    List<NameValuePair> nameValuePairList = new ArrayList<NameValuePair>();
                   // nameValuePairList.add(new BasicNameValuePair("name", name));
                    //nameValuePairList.add(new BasicNameValuePair("email", email));
                    nameValuePairList.add(new BasicNameValuePair("value", value));

                    try{
                        HttpClient httpClient = new DefaultHttpClient();
                        HttpPost httpPost = new HttpPost(url1);
                        httpPost.setEntity(new UrlEncodedFormEntity(nameValuePairList));
                        HttpResponse httpResponse = httpClient.execute(httpPost);
                        HttpEntity httpEntity = httpResponse.getEntity();
                        is = httpEntity.getContent();
                        //etName.setText("");
                        //etEmail.setText("");
                        //etPhone.setText("");
                        Toast.makeText(getApplicationContext(), successMessage, Toast.LENGTH_SHORT).show();
                        is.close();
                    }catch(IOException e){
                        Toast.makeText(getApplicationContext(), exceptionMessage, Toast.LENGTH_SHORT).show();
                    }
                //}
            }
        });
    }

    private class RetrieveTask extends AsyncTask<Void, Void, Void> {

        @Override
        protected Void doInBackground(Void... params) {

            try{
                HttpClient httpClient = new DefaultHttpClient();
                HttpPost httpPost = new HttpPost(url2);
                HttpResponse httpResponse = httpClient.execute(httpPost);
                HttpEntity httpEntity = httpResponse.getEntity();
                is = httpEntity.getContent();
            }catch (Exception e){
                Toast.makeText(getApplicationContext(), exceptionMessage+", Ex1", Toast.LENGTH_SHORT).show();
            }try{
                BufferedReader reader = new BufferedReader(new InputStreamReader(is, "iso-8859-1"), 8);
                StringBuilder sb = new StringBuilder();
                while((line=reader.readLine())!=null){
                    sb.append(line+"\n");
                }
                result = sb.toString();
                System.out.println("-----JSON Data-----");
                System.out.println(result);
                is.close();
            }catch(Exception e){
                Toast.makeText(getApplicationContext(), exceptionMessage+", Ex2", Toast.LENGTH_SHORT).show();
            }try{
                JSONArray jsonArray = new JSONArray(result);
                JSONObject jsonObject = jsonArray.getJSONObject(0);
                /*int totalCount = jsonArray.length();
                for(int i=0; i<totalCount; i++){
                    JSONObject jsonObject = jsonArray.getJSONObject(i);
                    names += jsonObject.getString("name")+":";
                    emails += jsonObject.getString("email")+":";
                    phones += jsonObject.getString("phone")+":";
                    combinedText += (i+1)+". Name '"+jsonObject.getString("name")+"', "+
                            "Email '"+jsonObject.getString("email")+"', "+
                            "Phone '"+jsonObject.getString("phone")+"':";
                }*/
                values = jsonObject.getInt("value");
                if(values == 1)
                {
                   combinedText = "The Door has been broken\n";
                }
                else if(values == 0)
                {
                    combinedText = "The door is secure\n";
                }

            }catch (Exception e){
                Toast.makeText(getApplicationContext(), exceptionMessage+", Ex3", Toast.LENGTH_SHORT).show();
            }

            return null;
        }

        @Override
        protected void onPostExecute(Void aVoid) {
            //name = names.split(":");
            //email = emails.split(":");
            //phone = phones.split(":");
            //combinedArray = combinedText.split(":");
            combinedArray =combinedText.split(":");
            listView.setAdapter(new ArrayAdapter<String>(MainActivity.this,
                    android.R.layout.simple_list_item_1, combinedArray));//changed combinedArray

            progressDialog.dismiss();
        }

        @Override
        protected void onPreExecute() {
            progressDialog = new ProgressDialog(MainActivity.this);
            progressDialog.setTitle("Loading...");
            progressDialog.setMessage("Please Wait ... ");
            progressDialog.setIcon(R.drawable.ic_play_for_work_black_24dp);
            progressDialog.setCancelable(false);
            progressDialog.show();
        }
    }

}
