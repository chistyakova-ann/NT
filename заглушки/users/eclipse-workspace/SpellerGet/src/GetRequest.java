
import java.io.IOException;
import org.apache.http.HttpEntity;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;
import org.apache.http.client.methods.*;


public class GetRequest {
static String sUrl="https://speller.yandex.net/services/spellservice";
	public static void main(String[] args) {
		CloseableHttpResponse resp1=null;
		try {
			CloseableHttpClient httpClient=HttpClients.createDefault();
			HttpGet httpGet = new HttpGet(sUrl+"/checkText?text=Helo,+меня+зовут+Чистякова+Анна+Сергевна.+"
					+"Имею+базовые+знани+языков+праграирования+C,+Jiva");
			resp1=httpClient.execute(httpGet);
			System.out.println(EntityUtils.toString(resp1.getEntity()));
		}
		catch(IOException e) {
			e.printStackTrace();
			
		}
		finally {
			try {
				resp1.close();
			}catch (IOException e) {
				e.printStackTrace();
			}
			
		}

	}

}
