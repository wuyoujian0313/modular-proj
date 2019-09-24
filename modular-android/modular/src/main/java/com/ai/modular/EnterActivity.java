package com.ai.modular;

import android.content.Intent;
import android.os.Bundle;
import com.ai.base.AIBaseActivity;
import com.ai.webplugin.AIWebViewActivity;
import com.ai.webplugin.config.GlobalCfg;

import java.io.InputStream;

public class EnterActivity extends AIBaseActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        initParam();
        enterHomeActivity();

    }

    private void initParam() {
        GlobalCfg globalCfg = GlobalCfg.getInstance();
        try {
            InputStream is = getResources().getAssets().open("global.properties");
            globalCfg.parseConfig(is);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    private void enterHomeActivity() {
        Intent intent = new Intent(this, AIWebViewActivity.class);

//        TypedValue typedValue = new TypedValue();
//        getTheme().resolveAttribute(R.attr.colorPrimary, typedValue, true);
//        final  int color = typedValue.data;
        intent.putExtra(AIWebViewActivity.backgroundColorKey,R.color.colorPrimary);
        intent.putExtra(AIWebViewActivity.backgroundResIdKey,R.color.colorPrimary);
        intent.putExtra(AIWebViewActivity.welcomeImageResId,R.mipmap.startpage);

        try {
            GlobalCfg globalCfg = GlobalCfg.getInstance();
            String flavor = BuildConfig.FLAVOR;
            if (flavor.equalsIgnoreCase("modular")) {
                intent.putExtra(AIWebViewActivity.webViewURLKey,globalCfg.attr("online.addr"));
            } else {
                intent.putExtra(AIWebViewActivity.webViewURLKey,globalCfg.attr("online.addrTest"));
            }

            startActivity(intent);
            finish();
        } catch (Exception e) {
        }
    }
}
