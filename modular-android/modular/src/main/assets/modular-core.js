window.modular = (function() {
	// 扩展区域
	var modular = (function(){
		return {
		    // 这个key生成的规则是：方法名称，即wade-plugin.xml里的name字段
            // 注意不要重复
			// 测试函数，后面的方法，请按照这个方法扩展自己的自定义的方法
			// 目前支持传给原生端的参数只有一个，类型: string, array,JSONObject(java侧是JSONObject,OC侧是NSDictionary)
			JN_Test:function(string,callback) {
				var callbackKey = 'JN_Test';
				modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,string);
			},

			//
            JN_JSONObj:function(obj,callback) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_JSONObj';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,obj);
            },

            // 扩展自己的接口
            // 退出应用
            JN_Quit:function(appName,callback) {
                var callbackKey = 'JN_Quit';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,appName);
            },

            // 分享应用链接到系统剪切板
            JN_Sharing:function(url,callback) {
                var callbackKey = 'JN_Sharing';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,url);
            },

            // 打开文档
            JN_OpenDocument:function(url,callback) {
                var callbackKey = 'JN_OpenDocument';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,url);
            },

            // 检查版本自动更新
            JN_CheckVersion:function(url,callback) {
                var callbackKey = 'JN_CheckVersion';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,url);
            },

            // 获取版本号
            JN_VersionNumber:function(callback) {
                var callbackKey = 'JN_VersionNumber';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey);
            },

            // 启动loading
            JN_ShowLoading:function(text,callback) {
                var callbackKey = 'JN_ShowLoading';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,text);
            },

            // 启动loading
            JN_DismissLoading:function(callback) {
                var callbackKey = 'JN_DismissLoading';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey);
            },

            // 提示语
            JN_ShowMessage:function(string) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_ShowMessage';
                modular.execute(callbackKey,string);
            },

            // 存储数据
            JN_SetValueWithKey:function(value,key) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_SetValueWithKey';
                modular.execute(callbackKey,[key,value]);
            },

            // 获取数据,通过回调返回数据
            JN_GetValueWithKey:function(key,callback) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_GetValueWithKey';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,key);
            },

            // 删除数据
            JN_RemoveValueWithKey:function(key,callback) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_RemoveValueWithKey';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,key);
            },

            // 指纹验证
            JN_Fingerprint:function(callback) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_Fingerprint';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey);
            },

            // 发送短信，第一个参数，手机号，第二个参数：短信内容
            JN_SMS:function(phoneNumber,content) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_SMS';
                if(content===null || content.length === 0) content=' ';
                modular.execute(callbackKey,[phoneNumber,content]);
            },

            // 拨打电话，参数，手机号
            JN_Telephone:function(phoneNumber) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_Telephone';
                modular.execute(callbackKey,phoneNumber);
            },

            // 发邮件
            //第一个参数收件人邮箱号
            //第二个参数邮件主题
            //第三个邮件正文
            JN_Email:function(address,subject,content) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_Email';
                modular.execute(callbackKey,[address,subject,content]);
            },

            // 打开浏览器，参数，网址
            JN_Brower:function(urlString) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_Brower';
                modular.execute(callbackKey,urlString);
            },

            // 打开相册选择图片，单张图片，图片数据通过base64回传
            JN_SelectPhoto:function(callback) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_SelectPhoto';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey);
            },

            // 打开系统相机拍照，图片，图片数据通过base64回传
            JN_Photograph:function(callback) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_Photograph';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey);
            },

            // 自定义证件拍照
            JN_TakeCertificate:function(callback) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_TakeCertificate';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey);
            },
            
            // 扫码
            JN_QRcode:function(callback) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_QRcode';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey);
            },
            // 
            JN_ASEEncrypt:function(content,callback) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_ASEEncrypt';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,content);
            },
            JN_ASEDecrypt:function(key,content,callback) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_ASEDecrypt';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,[key,content]);
            },
            //采集位置
            JN_MarkLocation:function(markParam,callback) {
                if (typeof(markParam)=="object" && (markParam instanceof Wade.DataMap)) {
                    var markParams = new Wade.DatasetList();
                    markParams.add(markParam);
                    markParam = markParams;
                }
                // 方法名，即配置中的name
                var callbackKey = 'JN_MarkLocation';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,markParam.toString());
            },
            
            //定位
            JN_SignInLocation:function(markParam,callback) {
            	if (typeof(markParam)=="object" && (markParam instanceof Wade.DataMap)) {
					var markParams = new Wade.DatasetList();
					markParams.add(markParam);
					markParam = markParams;
				}
                // 方法名，即配置中的name
                var callbackKey = 'JN_SignInLocation';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,markParam.toString());
            },
            
            //查看位置
            JN_ScanLocation:function(marks,callback) {
            	if (typeof(marks)=="object" && (marks instanceof Wade.DatasetList)) {
                    // 方法名，即配置中的name
                    var callbackKey = 'JN_ScanLocation';
                    modular.storeCallback(callbackKey,callback);
                    modular.execute(callbackKey,marks.toString());
				}
            },
            
            //打开在线附件
            JN_OpenOnlineFile:function(sessionId,fileId,fileName,filePath,callback) {
            	// 方法名，即配置中的name
                var callbackKey = 'JN_OpenOnlineFile';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,[sessionId,fileId,fileName,filePath]);
            },

            JN_UploadSingleFile:function(sessionId,filePath,callback) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_UploadSingleFile';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,[sessionId,filePath]);
            },
            
            JN_OpenOcrScanComp:function(param,callback) {
            	// 方法名，即配置中的name
                var callbackKey = 'JN_OpenOcrScanComp';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,param);
            },
            
            // 设置手势密码
            JN_SettingGesturePassword:function(username,callback) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_SettingGesturePassword';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,username);
            },
            
            // 提交手势密码的状态回调函数,statusCode='0'，成功，非"0":不成功
            JN_SettingGesturePasswordCallback:function(statusCode,statusDesc,callback) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_SettingGesturePasswordCallback';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,[statusCode,statusDesc]);
            },
            
            // 修改手势密码
            JN_ModifyGesturePassword:function(username,callback) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_ModifyGesturePassword';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,username);
            },
            
            // 修改手势密码的状态回调函数,statusCode='0'，成功，非"0":不成功
            JN_ModifyGesturePasswordCallback:function(statusCode,statusDesc,callback) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_ModifyGesturePasswordCallback';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,[statusCode,statusDesc]);
            },
            
            // 是否有手势密码
            JN_HaveGesturePassword:function(callback) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_HaveGesturePassword';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey);
            },

            JN_GesturePasswordLogin:function(callback) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_GesturePasswordLogin';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey);
            },

            // 手势密码登录的状态回调函数,statusCode='0'，成功，非"0":不成功
            JN_GesturePasswordLoginCallback:function(statusCode,statusDesc,callback) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_GesturePasswordLoginCallback';
                modular.storeCallback(callbackKey,callback);
                modular.execute(callbackKey,[statusCode,statusDesc]);
            },
            
            // 微信分享
            JN_WXShare:function(content) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_WXShare';
                modular.execute(callbackKey,content);
            },

            // 打开轻量级的WebViewActivity
            JN_OpenLightWebViewActivity:function(content) {
                // 方法名，即配置中的name
                var callbackKey = 'JN_OpenLightWebViewActivity';
                modular.execute(callbackKey,content);
            },
		};
	})();


    // 下面部分不需要修改！！！！！！
	// 全局变量
	var callbackMap = {};
	top['callbackMap'] = top['callbackMap']||{};
	
	// 存储回调
	modular.storeCallback=function(callbackKey,callback){
		if (callback) {
			var _iframeName = (window !== window.top)? window.name : null;
			top.callbackMap[callbackKey] = {
				callback: callback,
				iframeName: _iframeName
			};
		}
	}
	
	// 取出并执行回调
	modular.callback=function(callbackKey, data) {
		var callbackItem = top.callbackMap[callbackKey];
		if (callbackItem) {
			if (callbackItem.callback) {
				var func = callbackItem.callback, 
				    iframeName = callbackItem.iframeName
				;
				if(typeof func==="function"){
					if (iframeName){
						var _func = document[iframeName].eval(func);
						_func(data);
					} else {
						func(data);
					}
				}
		
	            if (callbackItem) {
	            	if(callbackKey =='JN_SettingGesturePassword' 
	            		|| callbackKey =='JN_GesturePasswordLogin' ) {
	            		//手势密码登录和设置手势密码不能删除回调函数，他需要多次回调
	       
	            	} else {
	            		delete top.callbackMap[callbackKey];
	            	}
			    }
			}
		}
	}

   modular.osName=function() {
        var u = window.navigator.userAgent;
        if(u.indexOf('_wade_mobile_modular_')>-1) {
             var isAndroid = u.indexOf('Android') > -1 || u.indexOf('Linux') > -1; //android
             var isIOS = !!u.match(/\(i[^;]+;( U;)? CPU.+Mac OS X/); //ios终端
             if (isAndroid) {
                 //android操作系统
                 return 'a';
             }
             if (isIOS) {
                 //iOS操作系统
                 return 'i';
             }
        } else {
             return 'p';
        }
   }

   modular.storage = {
        set:function(key,val){
        	localStorage.setItem(key,val);
        },
        get:function(key){
            return localStorage.getItem(key);
        },
        remove:function(key){ 
        	localStorage.removeItem(key); 
        }
    }

   modular.execute=function(pluginName,param) {
         //var paramString = '{"pluginName":"'+pluginName+'","params":'+param+'}';
         var paramObj = null;
         if(param == null) {
            paramObj = {"pluginName":pluginName};
         } else {
            paramObj = {"pluginName":pluginName,"params":param};
         }

         if (paramObj == null) return;
         var paramString = JSON.stringify(paramObj);
         if (modular.osName() =='a'){
             // android
             // android都调用JN_EXECUTE由这个函数进行方法的转发
             top.modularHander.JN_EXECUTE(paramString);
         } else if (modular.osName() == 'i') {
             // iOS
             // iOS都在WKWebview的WKScriptMessageHandler中进行转发
             window.webkit.messageHandlers.modularHander.postMessage(paramString);
         } else if(modular.osName() == 'p') {

             // PC端
             if (pluginName == 'JN_SetValueWithKey'
                 || pluginName == 'JN_GetValueWithKey'
                 || pluginName == 'JN_RemoveValueWithKey'
                 || pluginName == 'JN_SettingGesturePassword'
                 || pluginName == 'JN_GesturePasswordLogin'	 ) {
            	 
                if (pluginName == 'JN_SetValueWithKey') {
                    if (param.length >= 2) {
                        modular.storage.set(param[0],param[1]);
                    }
                } else if (pluginName == 'JN_GetValueWithKey') {
                    // key
                    if (param.length > 0) {
                        var value = modular.storage.get(param);
                        modular.callback(pluginName,value);
                    }
                } else if (pluginName == 'JN_RemoveValueWithKey') {
                    if (param.length > 0) {
                        var value = modular.storage.remove(param);
                    }
                } else if(pluginName == 'JN_SettingGesturePassword') {
                	// PC直接取消
                    modular.callback(pluginName,"-1");
                } else if(pluginName == 'JN_GesturePasswordLogin') {
                	// PC直接取消
                    modular.callback(pluginName,"0000");
                }

             } else {
                alert('请在手机APP中运行');
             }

         }
   }
   return modular;
})();


//$(function(){
//    // ios input
//    if($.os.ios && window.top !== window){
//        $('body').css('cursor','pointer');
//        $('input').bind('click',function(event){
//        this.ontouchend = function(e){
//            if(document.activeElement===this){
//                window.focus();
//                setTimeout(function(){
//                    this.focus();
//                },0);
//            }
//        }
//        event.stopPropagation()
//        });
//
//        $('body').bind('click',function(){
//        document.activeElement.blur();
//        });
//    }
//});
