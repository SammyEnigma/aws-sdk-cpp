/*
* Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#pragma once

#include <aws/polly-to-output/PollyToOutput_EXPORTS.h>
#include <aws/polly-to-output/PCMOutputDriver.h>

#include <Windows.h>

namespace Aws
{
    namespace PollyToOutput
    {
        class AWS_POLLY_OUT_API WaveOutPCMOutputDriver : public PCMOutputDriver
        {
        public:
            WaveOutPCMOutputDriver();
            virtual void WriteBufferToDevice(const unsigned char*, size_t) override;
            virtual Aws::Vector<DeviceInfo> EnumerateDevices() const override;
            virtual void SetActiveDevice(const DeviceInfo& device, const CapabilityInfo& caps) override; 

        private:
            void InitDevice();

            DeviceInfo m_activeDevice;
            CapabilityInfo m_selectedCaps;
            HWAVEOUT m_waveOut;
            bool m_isInit;
        };
    }
}