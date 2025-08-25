<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
<head>
    <title>Сортировка</title>
</head>
<body>
    <h1 align="center">XML</h1>
    <div>
        <div>
            <xsl:for-each select="note">
            <xsl:sort select="text" lang="ru"/>
            <div align="center" bgcolor="#9acd32"><xsl:value-of select="title"/></div>
            <div align="center"><xsl:value-of select="head"/></div>
            <div align="justify"><xsl:value-of select="text"/></div>
            </xsl:for-each>
        </div>
    </div>
</body>
</html>
</xsl:template>
</xsl:stylesheet>