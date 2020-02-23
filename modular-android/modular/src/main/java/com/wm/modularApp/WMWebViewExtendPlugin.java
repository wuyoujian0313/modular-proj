package com.wm.modularApp;

import android.app.Activity;
import android.content.Intent;
import android.webkit.WebView;

import com.wm.common.WMBaseActivity;
import com.wm.webviewkit.WMWebViewBasePlugin;


/**
 * author: wuyoujian
 * Date: 2018/12/19
 */
public class WMWebViewExtendPlugin extends WMWebViewBasePlugin {
    public WMWebViewExtendPlugin(WMBaseActivity activity, WebView webView) {
        super(activity,webView);
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode,data);
        if (resultCode == Activity.RESULT_OK) {
            if (requestCode == 1000) {
                if (data != null) {
                    final String result = data.getStringExtra("result");
                    this.callback("JN_QRcode", result);
                }
            }
        }
    }
}
