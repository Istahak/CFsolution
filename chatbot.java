import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.HttpURLConnection;
import java.net.URL;

public class chatbot {
    public static void main(String[] args) {
        System.out.println(chatgpt("Tell me a jokes"));
    }
    public static String chatgpt(String message){
        String url="https://api.openai.com/v1/chat/completions";
        String apikey="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";
        String model="gpt-3.5-turbo";
        try{
                //Create the HTTP POST request
                URL obj=new URL(url);
                HttpURLConnection con=(HttpURLConnection) obj.openConnection();
                con.setRequestMethod("POST");
                con.setRequestProperty("Authorization","Bearer "+apikey);
                con.setRequestProperty("Content-Type","application/json");

                //Build the request Body
                String body="{\"model\": \""+model+"\",\"message\": [{\"role\": \"user\",\"content\": \""+message+"\"}]}";
                con.setDoOutput(true);
                OutputStreamWriter writer=new OutputStreamWriter(con.getOutputStream());
                writer.write(body);
                writer.flush();
                writer.close();

                //Get the response
                BufferedReader in=new BufferedReader(new InputStreamReader(con.getInputStream()));
                String inputline;
                StringBuffer response=new StringBuffer();
                while((inputline=in.readLine())!=null){
                    response.append(inputline);
                }
                in.close();


                return (response.toString().split("\"content\":\"")[1].split("\"")[0]).substring(4);
                
                
        }catch(IOException e){
            throw new RuntimeException(e);
        }
        
    }
}