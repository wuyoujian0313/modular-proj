package com.wm.modularApp;

import android.content.Intent;
import android.os.Bundle;

import com.wm.BuildConfig;
import com.wm.common.WMBaseActivity;
import com.wm.webviewkit.WMWebViewActivity;
import com.wm.webviewkit.config.WMGlobalCfg;

import java.io.InputStream;

public class EnterActivity extends WMBaseActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        initParam();
        enterHomeActivity();

    }

    private void initParam() {
        WMGlobalCfg globalCfg = WMGlobalCfg.getInstance();
        try {
            InputStream is = getResources().getAssets().open("global.properties");
            globalCfg.parseConfig(is);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    private void enterHomeActivity() {
        Intent intent = new Intent(this, WMWebViewActivity.class);

//        TypedValue typedValue = new TypedValue();
//        getTheme().resolveAttribute(R.attr.colorPrimary, typedValue, true);
//        final  int color = typedValue.data;
        intent.putExtra(WMWebViewActivity.kBackgroundColorKey, R.color.colorPrimary);
        intent.putExtra(WMWebViewActivity.kBackgroundResIdKey,R.color.colorPrimary);
        intent.putExtra(WMWebViewActivity.kWelcomeImageResId,R.mipmap.startpage);
        intent.putExtra(WMWebViewActivity.kFullscreenType,WMWebViewActivity.WMFullScreenType.WMFullScreenTypeNoTitleBarInPortrait.value());

        try {
            WMGlobalCfg globalCfg = WMGlobalCfg.getInstance();
            intent.putExtra(WMWebViewActivity.kWebViewURLKey,globalCfg.attr("online.addr"));
            startActivity(intent);
            finish();
        } catch (Exception e) {
        }
    }
}
