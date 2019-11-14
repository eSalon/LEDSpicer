cat <<EOF >/etc/ledspicer.conf
<LEDSpicer
    version="1.0"
    type="Configuration"
    userId="1000"
    groupId="1000"
    fps="14"
    port="16161"
    colors="basicColors"
>
<devices>
<device
    name="UltimarcUltimate"
    boardId="1"
>
<element
    name="P1_START"
    led="4"
/>
</device>
</devices>
    <layout defaultProfile="default">
        <group name="Player1">
            <element name="P1_START"/>
        </group>
    </layout>
</LEDSpicer>
EOF


mkdir -p /usr/share/ledspicer/profiles
cat <<EOF >/usr/share/ledspicer/profiles/default.xml
<?xml version="1.0" encoding="UTF-8"?>
<LEDSpicer
        version="1.0"
        type="Profile"
        backgroundColor="Black"
>
        <startTransition
                type="Pulse"
                color="White"
                speed="Fast"
                filter="Combine"
                direction="ForwardBouncing"
        />
        <endTransition
                type="Pulse"
                color="White"
                speed="Fast"
                filter="Combine"
                direction="ForwardBouncing"
        />
        <animations>
                <animation name="example" />
        </animations>
</LEDSpicer>
EOF

mkdir -p /usr/share/ledspicer/animations
cat <<EOF > /usr/share/ledspicer/animations/example.xml
<?xml version="1.0" encoding="UTF-8"?>
<LEDSpicer
        version="1.0"
        type="Animation"
>
        <actor
                type="Filler"
                group="All"
                speed="Normal"
                filter="Normal"
                direction="Forward"
                color="White"
                mode="Linear"
        />
</LEDSpicer>
EOF


mkdir -p /usr/share/ledspicer
cat <<EOF >/usr/share/ledspicer/basicColors.xml
<?xml version="1.0" encoding="UTF-8"?>
<LEDSpicer
        version="1.0"
        type="Colors"
        format="hex"
>

        <color name="White"       color="FFFFFF" />
        <color name="LightGray"   color="C0C0C0" />
        <color name="Gray"        color="808080" />
        <color name="DimGray"     color="404040" />
        <color name="AlmostBlack" color="202020" />
        <color name="Black"       color="000000" />

        <color name="Red"         color="FF0000" />
        <color name="LightRed"    color="F03333" />
        <color name="DarkRed"     color="900000" />
        <color name="VeryDarkRed" color="330000" />
        <color name="Tomato"      color="660000" />
        <color name="Salmon"      color="A52A2A" />
        <color name="Coral"       color="D2691E" />

        <color name="Green"         color="00FF00" />
        <color name="LightGreen"    color="66FF66" />
        <color name="DarkGreen"     color="009900" />
        <color name="VeryDarkGreen" color="003300" />
        <color name="Lime"          color="B2FF66" />
        <color name="Olive"         color="808000" />

        <color name="Blue"         color="0000FF" />
        <color name="LightBlue"    color="6666FF" />
        <color name="DarkBlue"     color="00008B" />
        <color name="VeryDarkBlue" color="000033" />
        <color name="SlateBlue"    color="0066CC" />
        <color name="Violet"       color="4C0099" />
        <color name="Purple"       color="660066" />

        <color name="Yellow"         color="FFFF00" />
        <color name="LightYellow"    color="FFFF66" />
        <color name="DarkYellow"     color="666600" />
        <color name="Gold"           color="FFD700" />
        <color name="VeryDarkYellow" color="333300" />
        <color name="YellowGreen"    color="9ACD32" />

        <color name="Magenta"         color="FF00FF" />
        <color name="LightMagenta"    color="FF66FF" />
        <color name="DarkMagenta"     color="8B008B" />
        <color name="VeryDarkMagenta" color="660066" />
        <color name="Pink"            color="FF66B2" />
        <color name="HotPink"         color="CC00CC" />
        <color name="Maroon"          color="660033" />

        <color name="Cyan"         color="00FFFF" />
        <color name="LightCyan"    color="E0FFFF" />
        <color name="DarkCyan"     color="006666" />
        <color name="VeryDarkCyan" color="003333" />

        <color name="Orange"      color="FF9933" />
        <color name="LightOrange" color="994C00" />
        <color name="Brown"       color="663300" />
        <color name="DarkOrange"  color="331900" />
        <color name="Chocolate"   color="D2691E" />

</LEDSpicer>
EOF
