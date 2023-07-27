import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Solution {
    class PageInfo{
        String name;
        int basicScore;
        int outerCnt;
        double score;
        List<String> linkedPages;
    }
    
    public int solution(String word, String[] pages) {
        int answer = 0;
        word = word.toLowerCase();
        Matcher mt = null;
        
        List<String>[] datas = new List[pages.length];
        PageInfo[] pageInfos = new PageInfo[pages.length];
        
        for(int i = 0; i < pages.length; i++){
            int score = 0;
            pages[i] = pages[i].toLowerCase();
            datas[i] = new ArrayList<>();
            pageInfos[i] = new PageInfo();
            
            mt= Pattern.compile("<meta property=\"og:url\" content=\"https://(\\S*)\"").matcher(pages[i]);
            
            while(mt.find()){
                String name = mt.group(1).trim();
                pageInfos[i].name = name;    
            }
            
            mt = Pattern.compile("(?<=[^a-zA-Z])("+word+")[^a-zA-Z]").matcher(pages[i]);
            
            while(mt.find()){
                score += 1;
            }
            pageInfos[i].basicScore = score;
            
            mt = Pattern.compile("<a href=\"https://(\\S*)\"").matcher(pages[i]);
            
            while(mt.find()){
                String url = mt.group(1).trim();
                datas[i].add(url);
            }
            
            pageInfos[i].linkedPages = datas[i];
            pageInfos[i].outerCnt = datas[i].size();
        }
        
        for(int i = 0; i < pages.length; i++){
            for(String url : pageInfos[i].linkedPages){
                for(int j = 0; j < pages.length; j++){
                    if(i == j) continue;
                    
                    if(url.equals(pageInfos[j].name)){
                        pageInfos[j].score += (double) pageInfos[i].basicScore/pageInfos[i].outerCnt;
                    }
                }
            }
        }
        
        double max = 0;
        
        for(int i = 0; i < pages.length; i++){
            if(max < pageInfos[i].basicScore + pageInfos[i].score){
                max = pageInfos[i].basicScore + pageInfos[i].score;
                answer = i;
            }
        }
        
        
        return answer;
    }
}
