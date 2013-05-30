# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	kupfer
PORTVERSION=	208
CATEGORIES=	deskutils

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Convenient command and access tool

LICENSE=	GPLv3

BUILD_DEPENDS=	rst2html:${PORTSDIR}/textproc/py-docutils \
		xml2po:${PORTSDIR}/textproc/gnome-doc-utils \
		${PYTHON_PKGNAMEPREFIX}xdg>=0:${PORTSDIR}/devel/py-xdg \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}keyring>=0:${PORTSDIR}/security/py-keyring \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	keybinder>=0:${PORTSDIR}/x11/keybinder \
		${PYTHON_PKGNAMEPREFIX}gdata>=0:${PORTSDIR}/devel/py-gdata

USE_GITHUB=	yes
GH_ACCOUNT=	engla
GH_PROJECT=	kupfer
GH_TAGNAME=	master
GH_COMMIT=	04bbd63

USES=		desktop-file-utils shared-mime-info
USE_GNOME=	gvfs intltool pygtk2 pygnomedesktop
USE_PYTHON=	yes
INSTALLS_ICONS=	yes

MAN1=		kupfer.1
MLINKS=		kupfer.1 kupfer-exec.1

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.rst

DOCSRCDIR2=	${WRKSRC}/Documentation
DOCSDIR2=	${DOCSDIR}/Documentation
DOC_FILES2=	Contributing.rst GTKTheming.rst PluginAPI.rst VersionHistory.rst

OPTIONS_DEFINE=	NLS NAUTILUS RHYTHMBOX
NAUTILUS_DESC=	Enable Nautilus support
RHYTHMBOX_DESC=	Enable Rhythmbox plugins support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MNAUTILUS}
RUN_DEPENDS+=	${LOCALBASE}/lib/nautilus-python/nautilus:${PORTSDIR}/x11-fm/py-nautilus
.endif

.if ${PORT_OPTIONS:MRHYTHMBOX}
RUN_DEPENDS+=	rhythmbox:${PORTSDIR}/audio/rhythmbox
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|--quiet||' ${WRKSRC}/bin/kupfer.in
	@${REINPLACE_CMD} -e 's|locale.bindtextdomain|gettext.bindtextdomain|' \
		-e 's|locale.bind_textdomain_codeset|gettext.bind_textdomain_codeset|' \
		${WRKSRC}/kupfer/main.py

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/^build_subdirs/s|po||g' ${WRKSRC}/wscript
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf configure --mandir=${PREFIX}/man

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf build

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf install

post-install:
	${INSTALL_MAN} ${WRKSRC}/build/${MAN1} ${MAN1PREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.mk>
