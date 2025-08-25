<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
    <head>
        <title>Аттестация</title>
    </head>
    <body>
        <h1 align="center">Аттестация группы</h1>
        <table align="center" border="1" >
            <tr>
                <th>Студент</th>
                <th>Оценка</th>
            </tr>
            <xsl:for-each select="main/row">
            <xsl:sort select="student" lang="ru"/>
            <tr>
                <td><xsl:value-of select="student"/></td>
                <xsl:choose>
                    <xsl:when test="grade &lt; 4">
                        <td align="center" bgcolor="#FF0000"><xsl:value-of select="grade"/></td>
                    </xsl:when>
                     <xsl:when test="grade &gt; 8">
                        <td align="center" bgcolor="#008000"><xsl:value-of select="grade"/></td>
                    </xsl:when>
                    <xsl:otherwise>
                        <td align="center" bgcolor="#FFFFFF"><xsl:value-of select="grade"/></td>
                    </xsl:otherwise>
                </xsl:choose>
            </tr>
            </xsl:for-each>
        </table>
    </body>
</html>
</xsl:template>
</xsl:stylesheet>