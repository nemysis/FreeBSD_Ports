# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	jetspeed2
PORTVERSION=	2.2.2
CATEGORIES=	www java
MASTER_SITES=	APACHE/portals/jetspeed-2/sources
DISTNAME=	${PORTNAME:S/2/-2/}-${PORTVERSION}-source-release
DIST_SUBDIR=	java

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Open Source Portal, written in Java and XML

LICENSE=	AL2 BSD MIT CCbyNCSA25
LICENSE_COMB=	multi
LICENSE_NAME_CCbyNCSA25=Attribution-NonCommercial-ShareAlike 2.5 Unported
LICENSE_FILE_CCbyNCSA25=${WRKSRC}/CREATIVECOMMONS-LICENSE
LICENSE_PERMS_CCbyNCSA25=dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	${LOCALBASE}/bin/ant:${PORTSDIR}/devel/apache-ant

WRKSRC=		${WRKDIR}/${DISTNAME:C/-source-release//}
DATADIR=	${WEBAPPDIR}/${PORTNAME}

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

TOMCATDIR=	${PREFIX}/${TOMCATVER}
APPHOME=	${LOCALBASE}/${TOMCATVER}
WEBAPPDIR=	${TOMCATDIR}/webapps

PORTDOCS=	*

PLIST_SUB=	TOMCATDIR=${TOMCATDIR:S|^${PREFIX}/||}

OPTIONS_SINGLE=	AS
OPTIONS_SINGLE_AS=	TOMCAT6 TOMCAT7
OPTIONS_DEFAULT=	TOMCAT6

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTOMCAT6}
TOMCATVER=	apache-tomcat-6.0
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
.endif

.if ${PORT_OPTIONS:MTOMCAT7}
TOMCATVER=	apache-tomcat-7.0
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat7
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat7
.endif

do-install:
	${INSTALL} -d -o ${WWWOWN} -g ${WWWGRP} ${WEBAPPDIR}/${PORTNAME}
.for d in app-servers applications components enterprise etc jetspeed* maven openid-step2 src
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${WEBAPPDIR}/${PORTNAME})
.endfor
.for d in .checkstyle *.xml jetspeed2.checkstyle
	@(cd ${WRKSRC} && ${INSTALL_DATA} ${d} ${WEBAPPDIR}/${PORTNAME})
.endfor

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/release/* ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
