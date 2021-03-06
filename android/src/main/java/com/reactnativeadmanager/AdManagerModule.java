package com.reactnativeadmanager;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.module.annotations.ReactModule;

@ReactModule(name = AdManagerModule.NAME)
public class AdManagerModule extends ReactContextBaseJavaModule {
    public static final String NAME = "AdManager";

    private static native void initialize(long jsiPtr, String docDir);

    public AdManagerModule(ReactApplicationContext reactContext) {
        super(reactContext);
    }

    @Override
    @NonNull
    public String getName() {
        return NAME;
    }

    @ReactMethod(isBlockingSynchronousMethod = true)
    public boolean install() {
        try {
            System.loadLibrary(NAME);

            ReactApplicationContext context = getReactApplicationContext();
            initialize(
                    context.getJavaScriptContextHolder().get(),
                    context.getFilesDir().getAbsolutePath());
            return true;
        } catch (Exception exception) {
            return false;
        }
    }
}
