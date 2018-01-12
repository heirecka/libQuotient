#pragma once

#include "generated/content-repo.h"

namespace QMatrixClient
{
    class DownloadFileJob : public GetContentJob
    {
        public:
            enum { FileError = BaseJob::UserDefinedError + 1 };

            DownloadFileJob(const QString& serverName, const QString& mediaId,
                            const QString& localFilename = {});

            QString targetFileName() const;

        private:
            class Private;
            QScopedPointer<Private> d;

            void beforeStart(const ConnectionData*) override;
            void afterStart(const ConnectionData*,
                            QNetworkReply* reply) override;
            void beforeAbandon(QNetworkReply*) override;
            Status parseReply(QNetworkReply*) override;
    };
}
