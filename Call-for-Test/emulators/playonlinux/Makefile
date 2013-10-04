# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	playonlinux
PORTVERSION=	4.2.1
CATEGORIES=	emulators deskutils python
MASTER_SITES=	http://www.playonlinux.com/script_files/PlayOnLinux/${PORTVERSION}/
DISTNAME=	PlayOnLinux_${PORTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Easily install and use games and apps designed to run with Windows

LICENSE=	GPLv3

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/share/wine/gecko/wine_gecko-1.9-x86.msi:${PORTSDIR}/emulators/wine-gecko-devel \
		pyuic4:${PORTSDIR}/devel/py-qt4-core \
		xterm:${PORTSDIR}/x11/xterm \
		cabextract:${PORTSDIR}/archivers/cabextract \
		icotool:${PORTSDIR}/graphics/icoutils \
		convert:${PORTSDIR}/graphics/ImageMagick \
		glxinfo:${PORTSDIR}/graphics/mesa-demos \
		lspci:${PORTSDIR}/sysutils/pciutils \
		unzip:${PORTSDIR}/archivers/unzip \
		unrar:${PORTSDIR}/archivers/unrar \
		p7zip:${PORTSDIR}/archivers/p7zip \
		wget:${PORTSDIR}/ftp/wget \
		gsed:${PORTSDIR}/textproc/gsed \
		gpg:${PORTSDIR}/security/gnupg

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PYTHON=	yes
USE_WX=		yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64

PORTDOCS=	CHANGELOG TRANSLATORS

SUB_FILES=	${PORTNAME}.sh pkg-message changetmp

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
RUN_DEPENDS+=	wine:${PORTSDIR}/emulators/wine-devel
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^Icon.*|Icon=${PORTNAME}|' \
		-e 's|^Categories.*|Categories=Utility;Game;|' \
		${WRKSRC}/etc/PlayOnLinux.desktop

	@${REINPLACE_CMD} -e 's|"$$(uname -s)" = "Linux"|"$$(uname -s)" = "FreeBSD"|' \
		-e 's|linux system|FreeBSD system|' \
		-e 's|export PYTHON="python"|export PYTHON="${PYTHON_CMD}"|' \
		-e 's|POL_OS="Linux"|POL_OS="FreeBSD"|' \
		-e 's|python2.6 mainwindow.py|"${PYTHON_CMD}" mainwindow.py|' \
		${WRKSRC}/playonlinux*

	@${FIND} ${WRKSRC} -type f -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} \
		-e 's|"$$POL_OS" = "Linux"|"$$POL_OS" = "FreeBSD"|g' \
		-e 's|== "Linux"|== "FreeBSD"|g' \
		-e 's|vprefix="linux-"|vprefix="freebsd-"|g' \
		-e 's|os_pref = "linux"|os_pref = "freebsd"|g' \
		-e 's|/bin/bash|${PREFIX}/bin/bash|' \
		-e 's|/usr/bin/python|${PYTHON_CMD}|' \
		-e 's|sed -ue|gsed -ue|g'

	@${REINPLACE_CMD} -e 's|/etc/bash_completion|${PREFIX}/etc/bash_completion|' \
		-e 's|/usr/bin/lesspipe|/usr/bin/lesspipe.sh|' \
		${WRKSRC}/etc/pol_bash

	@${REINPLACE_CMD} -e 's|/etc/mtab|/compat/linux/proc/mtab|' \
		${WRKSRC}/lib/playonlinux.lib

	@${REINPLACE_CMD} -e 's|Plinux|Pfreebsd|g' \
		${WRKSRC}/lib/plugins.lib

	@${REINPLACE_CMD} -e 's|md5sum|md5|g' \
		-e 's|lsb_release -d|uname -rv|' \
		${WRKSRC}/lib/scripts.lib ${WRKSRC}/lib/variables

	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/python/lib/lng.py

	@${FIND} ${WRKSRC} -name "*.bak" -delete -or -name "*.orig" -delete

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}

	@${REINPLACE_CMD} -e 's|%%REINPLACE_CMD%%|${REINPLACE_CMD}|' \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/changetmp

.for f in resources lib plugins
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${DATADIR})
.endfor

	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}* ${DATADIR}

	@(cd ${WRKSRC} && ${COPYTREE_SHARE} bash ${DATADIR})
	@(cd ${DATADIR} && ${CHMOD} -R 775 bash)
	${INSTALL_SCRIPT} ${WRKDIR}/changetmp ${DATADIR}/bash

	@${MKDIR} ${DATADIR}/python/lib
	${INSTALL_SCRIPT} ${WRKSRC}/python/*.py ${DATADIR}/python
	${INSTALL_SCRIPT} ${WRKSRC}/python/lib/*.py ${DATADIR}/python/lib

.for f in install onglet setups
	@(cd ${WRKSRC}/etc && ${COPYTREE_SHARE} ${f} ${DATADIR}/etc)
.endfor
.for f in *.gif *.gpg *.png pol_bash
	(cd ${WRKSRC}/etc && ${INSTALL_DATA} ${f} ${DATADIR}/etc)
.endfor

post-install:
	${LN} -sf ${DATADIR}/etc/${PORTNAME}32.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/etc/PlayOnLinux.desktop ${PREFIX}/share/applications
#	cd ${WRKSRC}/etc && ${INSTALL_DATA} *.desktop PlayOnLinux.directory playonlinux-Programmes.menu \
#		${PREFIX}/share/applications

.if ${PORT_OPTIONS:MNLS}
	@(cd ${WRKSRC}/lang/locale && ${COPYTREE_SHARE} . ${PREFIX}/share/locale)
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
