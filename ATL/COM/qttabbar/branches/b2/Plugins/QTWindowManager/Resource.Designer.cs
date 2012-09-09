//    This file is part of QTTabBar, a shell extension for Microsoft
//    Windows Explorer.
//    Copyright (C) 2010  Quizo, Paul Accisano
//
//    QTTabBar is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    QTTabBar is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with QTTabBar.  If not, see <http://www.gnu.org/licenses/>.

﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:2.0.50727.4927
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace QuizoPlugins {
    using System;
    
    
    /// <summary>
    ///   A strongly-typed resource class, for looking up localized strings, etc.
    /// </summary>
    // This class was auto-generated by the StronglyTypedResourceBuilder
    // class via a tool like ResGen or Visual Studio.
    // To add or remove a member, edit your .ResX file then rerun ResGen
    // with the /str option, or rebuild your VS project.
    [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Resources.Tools.StronglyTypedResourceBuilder", "2.0.0.0")]
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
    [global::System.Runtime.CompilerServices.CompilerGeneratedAttribute()]
    internal class Resource {
        
        private static global::System.Resources.ResourceManager resourceMan;
        
        private static global::System.Globalization.CultureInfo resourceCulture;
        
        [global::System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1811:AvoidUncalledPrivateCode")]
        internal Resource() {
        }
        
        /// <summary>
        ///   Returns the cached ResourceManager instance used by this class.
        /// </summary>
        [global::System.ComponentModel.EditorBrowsableAttribute(global::System.ComponentModel.EditorBrowsableState.Advanced)]
        internal static global::System.Resources.ResourceManager ResourceManager {
            get {
                if (object.ReferenceEquals(resourceMan, null)) {
                    global::System.Resources.ResourceManager temp = new global::System.Resources.ResourceManager("QuizoPlugins.Resource", typeof(Resource).Assembly);
                    resourceMan = temp;
                }
                return resourceMan;
            }
        }
        
        /// <summary>
        ///   Overrides the current thread's CurrentUICulture property for all
        ///   resource lookups using this strongly typed resource class.
        /// </summary>
        [global::System.ComponentModel.EditorBrowsableAttribute(global::System.ComponentModel.EditorBrowsableState.Advanced)]
        internal static global::System.Globalization.CultureInfo Culture {
            get {
                return resourceCulture;
            }
            set {
                resourceCulture = value;
            }
        }
        
        internal static System.Drawing.Bitmap QTWindowManager_large {
            get {
                object obj = ResourceManager.GetObject("QTWindowManager_large", resourceCulture);
                return ((System.Drawing.Bitmap)(obj));
            }
        }
        
        internal static System.Drawing.Bitmap QTWindowManager_small {
            get {
                object obj = ResourceManager.GetObject("QTWindowManager_small", resourceCulture);
                return ((System.Drawing.Bitmap)(obj));
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to Window manager option;Enlarge window;Shrink window;Widen window;Narrow widnow;Heighten window;Lower window;Restore initial size;Move window left;Move window right;Move window up;Move window down;Maximize window;Minimize window;Restore window;Window manager.
        /// </summary>
        internal static string ResStrs {
            get {
                return ResourceManager.GetString("ResStrs", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to ウィンドウマネージャ オプション;ウィンドウ拡大;ウィンドウ縮小;幅拡大;幅縮小;高さ拡大;高さ縮小;元のサイズに戻す;ウィンドウを左へ;ウィンドウを右へ;ウィンドウを上へ;ウィンドウを下へ;最大化;最小化;元に戻す;ウィンドウマネージャ.
        /// </summary>
        internal static string ResStrs_ja {
            get {
                return ResourceManager.GetString("ResStrs_ja", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to .
        /// </summary>
        internal static string ResStrs_Options {
            get {
                return ResourceManager.GetString("ResStrs_Options", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to 起動時のサイズ;起動時の位置;サイズを復元;位置を復元;リサイズするとき位置も自動で調整;リサイズ/移動時のピクセル;プリセット;設定;削除;OK;キャンセル;現在の位置取得;現在のサイズ取得;起動時プリセット;取得.
        /// </summary>
        internal static string ResStrs_Options_ja {
            get {
                return ResourceManager.GetString("ResStrs_Options_ja", resourceCulture);
            }
        }
    }
}
