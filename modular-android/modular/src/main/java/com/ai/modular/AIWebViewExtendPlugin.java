package com.ai.modular;

import android.app.Activity;
import android.content.Intent;
import android.webkit.WebView;
import com.ai.base.AIBaseActivity;
import com.ai.webplugin.AIWebViewBasePlugin;



/**
 * author: wuyoujian
 * Date: 2018/12/19
 */
public class AIWebViewExtendPlugin extends AIWebViewBasePlugin {
    public AIWebViewExtendPlugin(AIBaseActivity activity, WebView webView) {
        super(activity,webView);
    }


    public void JN_QRcode() {
        Intent intent = new Intent();
        intent.setClass(getActivity(), ScanActivity.class);
        intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        getActivity().startActivityForResult(this,intent,1000);
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
