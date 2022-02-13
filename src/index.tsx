import type { FC } from 'react';
import { NativeModules } from 'react-native';

// const LINKING_ERROR =
//   `The package 'react-native-ad-manager' doesn't seem to be linked. Make sure: \n\n` +
//   Platform.select({ ios: "- You have run 'pod install'\n", default: '' }) +
//   '- You rebuilt the app after installing the package\n' +
//   '- You are not using Expo managed workflow\n';

// const AdManager = NativeModules.AdManager
//   ? NativeModules.AdManager
//   : new Proxy(
//       {},
//       {
//         get() {
//           throw new Error(LINKING_ERROR);
//         },
//       }
//     );

const g = global as any;

const AdManagerModule = NativeModules.AdManager;

if (AdManagerModule && typeof AdManagerModule.install === 'function') {
  AdManagerModule.install();
}

type HelloWorldProps = {};

export const HelloWorld: FC<HelloWorldProps> = () => g.helloWorld();
